using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo (3 filas x 4 columnas)
        int[,] matriz = {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 }
        };

        Console.WriteLine("Matriz original:");
        ImprimirMatriz(matriz);

        // Intercambiamos la columna 0 con la columna 2
        IntercambiarColumnas(matriz, 0, 2);

        Console.WriteLine("\nMatriz después de intercambiar columnas 0 y 2:");
        ImprimirMatriz(matriz);
    }

    static void IntercambiarColumnas(int[,] matriz, int col1, int col2)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        // Validamos que los índices de las columnas existan en la matriz
        if (col1 < 0 || col1 >= columnas || col2 < 0 || col2 >= columnas)
        {
            Console.WriteLine("Error: Uno o ambos índices de columna están fuera de rango.");
            return;
        }

        // Si las columnas son iguales, no hace falta hacer nada
        if (col1 == col2) return;

        // Recorremos fila por fila intercambiando los valores de las dos columnas
        for (int i = 0; i < filas; i++)
        {
            int temp = matriz[i, col1];
            matriz[i, col1] = matriz[i, col2];
            matriz[i, col2] = temp;
        }
    }

    // Método auxiliar para mostrar la matriz en consola
    static void ImprimirMatriz(int[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                Console.Write(matriz[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
