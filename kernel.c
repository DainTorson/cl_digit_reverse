__kernel void reverse(__global int * input, __global int * output, int length)
{
	int gid = get_global_id(0);

	if(gid < length / 2)
	{
		output[(length - 1) - gid] = input[gid];
		output[gid] = input[(length - 1) - gid];
	}

	if(length % 2 != 0 && gid == length / 2)
	{
		output[gid] = input[gid];
	}
	barrier(CLK_LOCAL_MEM_FENCE);
}