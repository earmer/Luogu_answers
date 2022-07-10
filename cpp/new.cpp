#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

int iterater_index(int *index, int M, int K, int *times, int real_sum_length) {

    if (*times > M) {
        return 0;
    }

    if (*times >= 1) {
        index[M - *times] = index[M - *times] + 1;
        for (int i = *times - 1; i >= 0; i--) {
            index[M - i] = index[M - i - 1] + K;
        }

    }
    if (*times == 0) {
        index[M]++;
    }

    if (index[M] > real_sum_length - 1) {
        (*times)++;
        iterater_index(index, M, K, times, real_sum_length);
    } else {
        *times = 0;
        return 1;
    }

}

int choose_num(int *a, int N, int M, int K) {
    //第一步，往数组a两边插0以方便算和数列
    int real_a_length = N + 2 * (K - 1);
    long *real_a = (long *) malloc(sizeof(long) * real_a_length);
    int real_sum_length = N + (K - 1);
    long *sum = (long *) malloc(sizeof(long) * real_sum_length);

    //插0
    for (int i = 0; i < real_a_length; i++) {
        real_a[i] = 0;

    }
    //拷贝原数值
    for (int i = K - 1; i < K + N - 1; i++) {
        real_a[i] = a[i - (K - 1)];
    }


    //造和数列sum
    for (int i = 0; i < real_sum_length; i++) {
        sum[i] = 0;
        for (int j = 0; j < K; j++) {
            sum[i] = sum[i] + real_a[i + j];
        }
//        std::cout << sum[i] << " ";   //输出所有和数列
    }
//    std::cout << std::endl;



    //第二步，生成和数列的候选序列组，若和数列长度为8，k = 3, M=3,序列组应该是{0,3,6},{0,3,7},{0,4,7}
    int index[M];
    for (int i = 0; i < M; i++) {
        index[i] = i * K;
    }


    long long total_max_sum = 0;
    int times = 0;


    while (1) {
        for (int i = 0; i < M; i++) {
//            std::cout << index[i] << " ";
        }
//        std::cout << std::endl;


        long total_sum = 0;

        for (int j = 0; j < M; j++) {
//            total_sum = total_sum + sum[index[j]];
        }
//        std::cout << total_sum << std::endl;

        if (total_sum > total_max_sum) {
            total_max_sum = total_sum;
        }

        //根据当前候选序列组迭代至下一个候选序列组，此递归函数的返回值指示是否为最后一个序列组，若是则迭代完毕
        if (iterater_index(index, M - 1, K, &times, real_sum_length) == 0)
            break;
    }

    return total_max_sum;

}

int main() {
    setbuf(stdout, NULL);
    //int a[] = {102,1,100,100,100,1};
    //int a[] = {10,5,34,4,26,12,75,15,8,20};

    int a[100005];
    int N;
    //int M = 3; //区间个数
    //int K = 3; //区间长度
    //int M = 3; //区间个数
    //int K = 2; //区间长度
    int M = 4; //区间个数
    int K = 1; //区间长度
    std::cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    long long total_max_sum = choose_num(a, N, M, K);


    /*  单独测试候选序列组的函数
    int index[] = {0,3,6};
    int times = 0;

    while(1)
    {
        for(int i = 0; i < M; i++)
        {
            std::cout << index[i] << " ";
        }

        if(iterater_index(index,M-1,K, &times,9) == 0)
            break;

         std::cout << std::endl;
    }
    */
    std::cout << total_max_sum << std::endl;
    return 0;
}



