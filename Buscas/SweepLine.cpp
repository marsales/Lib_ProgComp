// SWEEP LINE ===============================================

/*
Problema: Dados N intervalos abertos e Q queries, 
descubra para cada query em quantos intervalos ela se encontra.

MAXN -> número máximo de coordenadas
*/

// Vetor contendo os intervalos inputados
vii intervals;

vi contador(MAXN+1, 0);
vi psum(MAXN+1, 0);

for (auto [l,r] : intervals) {
    contador[l]++;
    contador[r]--;
}

psum[0] = 0;
for (int i = 0; i < MAXN; i++) {
    psum[i+1] = contador[i] + psum[i];
}

// psum[x] -> quantos estão na posição x


// SWEEP LINE + Compressão de Coordenadas ===================
/*
Se MAXN = 10^9, mas na prática só haver até 10^5 ou 10^6 coordenadas,
teremos que usar compressão de coordenadas
*/

// Vetor contendo os intervalos inputados
vllll intervals;

// Vetor com todas as coordenadas inputadas
vll coords;

// Sortar as coordenadas e deixar apenas uma de cada
sort(coords.begin(), coords.end());
coords.erase(unique(coords.begin(), coords.end()), coords.end());

for (auto [l,r] : events) {
    ll pos1 = lb(coords.begin(), coords.end(), l) - coords.begin();
    ll pos2 = lb(coords.begin(), coords.end(), r) - coords.begin();
    contador[pos1]++;
    contador[pos2]--;
}

psum[0] = 0;
for (ll i = 0; i < sz; i++) {
    psum[i+1] = contador[i] + psum[i];
}

// psum[(ub(coords.begin(), coords.end(), pos) - coords.begin())] -> quantos estão na posição pos
