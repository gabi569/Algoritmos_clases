using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo de 3x4
        int[,] matriz = {
            { 1,  2,  3,  4 },
            { 5,  6,  7,  8 },
            { 9, 10, 11, 12 }
        };

        Console.WriteLine("Matriz original:");
        ImprimirMatriz(matriz);

        // Intercambiamos la fila 0 con la fila 2
        IntercambiarFilas(matriz, 0, 2);

        Console.WriteLine("\nMatriz después de intercambiar la fila 0 y la 2:");
        ImprimirMatriz(matriz);
    }
    static void IntercambiarFilas(int[,] matriz, int fila1, int fila2)
    {
        int totalFilas = matriz.GetLength(0);
        int totalColumnas = matriz.GetLength(1);

        // Validar que los índices estén dentro de los límites de la matriz
        if (fila1 < 0 || fila1 >= totalFilas || fila2 < 0 || fila2 >= totalFilas)
        {
            Console.WriteLine("Error: Uno o ambos índices de fila están fuera de rango.");
            return;
        }

        // Si las filas son iguales, no es necesario hacer nada
        if (fila1 == fila2) return;

        // Recorrer cada columna e intercambiar los elementos usando una variable auxiliar
        for (int col = 0; col < totalColumnas; col++)
        {
            int temp = matriz[fila1, col];
            matriz[fila1, col] = matriz[fila2, col];
            matriz[fila2, col] = temp;
        }
    }

    // Método auxiliar para visualizar la matriz en consola
    static void ImprimirMatriz(int[,] matriz)
    {
        for (int i = 0; i < matriz.GetLength(0); i++)
        {
            for (int j = 0; j < matriz.GetLength(1); j++)
            {
                Console.Write(matriz[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
