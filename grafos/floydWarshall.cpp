// Encontrar menor caminho entre cada par de vértices
// Retorna 1 se tiver ciclo negativo e 0 se não tiver

int n = /* número de vértices */ ;
int d[MAX][MAX];

bool floydWarshall() {
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 0; i < n; i++)
		if (d[i][i] < 0) return 1;
}

int main() {

    // ======== INICIALIZAÇÃO ========
    // Se i != j -> distância infinita
    // Se i == j -> distância zero
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i != j) d[i][j] = INF;
            else d[i][j] = 0;
        }

    for (int i = 0; i < edges; i++) {
        int a, b, w; // Vértices a e b ligados por aresta de peso w
        d[a][b] = w;
        d[b][a] = w;
}
