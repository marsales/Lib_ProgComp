// LONGEST INCREASING SUBSEQUENCE

/*
Problema: Dado um array, queremos achar o tamanho da maior 
subsequência estritamente crescente

length[k] -> tamanho da maior subsequência crescente que termina em k

Para cada array[k], verificamos todos os valores array[i] tal que i < k
*/


for (int k = 0; k < n; k++) {
  
    length[k] = 1;
    for (int i = 0; i < k; i++) {
      
        if (array[i] < array[k]) {
            length[k] = max(length[k], length[i]+1);
        }
    }
}
