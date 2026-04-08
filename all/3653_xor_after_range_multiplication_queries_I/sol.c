#define MODULO_LL (1000000007LL)

int xorAfterQueries(
    int* nums,
    int numsSize,
    int** queries,
    int queriesSize,
    int* queriesColSize
) {
    int result = 0;
    long long multiplier_ll = 0LL;

    for (int query_id = 0; query_id < queriesSize; ++query_id) {
        multiplier_ll = ((long long)queries[query_id][3]);

        for (
            int i = (queries[query_id][0]);
            i <= (queries[query_id][1]);
            i += (queries[query_id][2])
        ) {
            nums[i] = (int)((((long long)nums[i]) * multiplier_ll) % MODULO_LL);
        }
    }

    for (int i = 0; i < numsSize; ++i) {
        result ^= (nums[i]);
    }

    return result;
}
