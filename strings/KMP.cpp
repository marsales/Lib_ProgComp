// KMP
// Encontrar as ocorrências de uma string P numa string T

// Time: O(n + m)

const int MAX_N;
string T, P;    // T = text, P = pattern
int n, m;       // n = |T|, m = |P|
vi b;           // b = back table

void kmpPreprocess() { 
    int i = 0, j = -1; b[0] = -1;
    while (i < m) { // pre-process P
        while ((j >= 0) && (P[i] != P[j])) j = b[j]; 
        ++i; ++j; 
        b[i] = j;
    }
}

void kmpSearch() { 
    int i = 0, j = 0; 
    while (i < n) { 
        while ((j >= 0) && (T[i] != P[j])) j = b[j];
        ++i; ++j;
        if (j == m) {
            printf("P is found at index %d in T\n", i-j);
            j = b[j];
        }
    }
}
