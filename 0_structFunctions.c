
// GLOBAL VAR

struct Results {
    int *A;
    int N;
};

struct Results solution(int A[], int N, int K);


// MAIN
int main(void){
    
    // LOCAL VAR
    struct Results outp;
    
    /*
     OU
     struct Results result = { calloc(M, sizeof(int)),n ,k };
     */
    
    outp = solution(a,n,k);
    
    // print solução
    for(int i = 0; i < n; i++) {printf("%d ", a[i]);} printf("\n");
    
}


// FUNCTIONS
struct Results solution(int A[], int N, int K) {
    struct Results result;
    
    int* B = malloc( sizeof(int) * N);
    
    result.A = B;
    result.N = N;
    return result;
}
