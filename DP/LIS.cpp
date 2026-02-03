// LONGEST INCREASING SUBSEQUENCE

/*
Problema: Dado um array, queremos achar o tamanho da maior 
subsequência estritamente crescente
*/

// =============== Implementção O(n^2) ===============
/* 
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


// ============= Implementção O(nlog(n)) =============
/*
ans.size() -> resposta
*/
ans.push_back(arr[0]);

for (int i = 1; i < n; i++) {
    if (arr[i] > ans.back()) {
        ans.push_back(arr[i]);
    }
    else {
        int low = lower_bound(ans.begin(), ans.end(), arr[i] - ans.begin();
        ans[low] = arr[i];
    }
            
}




