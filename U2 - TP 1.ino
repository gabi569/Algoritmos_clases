using System;

class Program
{
    static void Main(string[] args)
    {
        // Puedes probar tus métodos aquí llamándolos desde el Main.
        Console.WriteLine("--- Pruebas de Métodos ---");
        
        // Ejemplo Ejercicio 6 (Verificación de estrictamente creciente)
        int[] arregloEjemplo = { 1, 3, 5, 2, 4, 6, 8, 8, 9, 10 };
        int rupturas = EstrictamenteCreciente(arregloEjemplo);
        Console.WriteLine($"Cantidad de rupturas en el orden estrictamente creciente: {rupturas}");
    }

    // ==========================================
    // MÉTODOS AUXILIARES (Reutilizables)
    // ==========================================

    // Método auxiliar para invertir un arreglo (necesario para Ejercicio 1)
    public static int[] InvertirArreglo(int[] arr)
    {
        int[] invertido = new int[arr.Length];
        for (int i = 0; i < arr.Length; i++)
        {
            invertido[i] = arr[arr.Length - 1 - i];
        }
        return invertido;
    }

    // Método auxiliar para calcular el producto escalar (necesario para Ejercicio 1)
    public static int CalcularProductoEscalar(int[] arr1, int[] arr2)
    {
        int producto = 0;
        for (int i = 0; i < arr1.Length; i++)
        {
            producto += arr1[i] * arr2[i];
        }
        return producto;
    }

    // ==========================================
    // EJERCICIO 1: Producto Escalar con Inverso
    // ==========================================
    public static int ProductoEscalarConInverso(int[] arr1, int[] arr2)
    {
        // Reutilizamos los métodos creados previamente
        int[] arr2Invertido = InvertirArreglo(arr2);
        return CalcularProductoEscalar(arr1, arr2Invertido);
    }

    // ==========================================
    // EJERCICIO 2: Búsqueda Lineal
    // ==========================================
    public static int BusquedaL(int[] arr, int valorBuscado)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] == valorBuscado)
            {
                return i; // Devuelve la posición donde se encuentra
            }
        }
        return -1; // Valor centinela que indica que no se encuentra en el arreglo
    }

    // ==========================================
    // EJERCICIO 3: Ordenar (Método Burbuja)
    // ==========================================
    public static int[] Ordenar(int[] arr)
    {
        for (int i = 0; i < arr.Length - 1; i++)
        {
            for (int j = 0; j < arr.Length - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int aux = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = aux;
                }
            }
        }
        return arr;
    }

    // ==========================================
    // EJERCICIO 4: Búsqueda Binaria
    // ==========================================
    public static int BusquedaB(int[] arrOrdenado, int valorBuscado)
    {
        int inicio = 0;
        int fin = arrOrdenado.Length - 1;

        while (inicio <= fin)
        {
            int medio = inicio + (fin - inicio) / 2;

            if (arrOrdenado[medio] == valorBuscado)
            {
                return medio;
            }
            else if (arrOrdenado[medio] < valorBuscado)
            {
                inicio = medio + 1;
            }
            else
            {
                fin = medio - 1;
            }
        }
        return -1; // No encontrado
    }

    // ==========================================
    // EJERCICIO 5: Intercalar en Arreglo Ordenado
    // ==========================================
    public static int[] Intercalar(int[] arr, int n, int nuevoValor)
        {
        // arr tiene N + 1 posiciones, pero solo las primeras N contienen elementos ordenados.
        int i = n - 1;

        // Desplazamos hacia la derecha los elementos mayores que el nuevo valor
        while (i >= 0 && arr[i] > nuevoValor)
        {
            arr[i + 1] = arr[i];
            i--;
        }

        // Insertamos el nuevo valor en la posición correcta que quedó libre
        arr[i + 1] = nuevoValor;

        return arr;
    }

    // ==========================================
    // EJERCICIO 6: Verificar Orden Estrictamente Creciente
    // ==========================================
    public static int EstrictamenteCreciente(int[] arr)
    {
        int rupturas = 0;

        for (int i = 0; i < arr.Length - 1; i++)
        {
            // Para que sea estrictamente creciente, el elemento siguiente DEBE ser mayor (>)
            // Si es menor o igual (>=), se rompe el orden.
            if (arr[i] >= arr[i + 1])
            {
                rupturas++;
            }
        }

        return rupturas;
    }
}
