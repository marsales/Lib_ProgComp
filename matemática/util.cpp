// Checar se x é quadrado
bool is_square(int x) {
    int r = sqrt(x);
    while ((r + 1) * 1LL * (r + 1) <= x) r++;
    while (r * 1LL * r > x) r--;
    return r * 1LL * r == x;
}
