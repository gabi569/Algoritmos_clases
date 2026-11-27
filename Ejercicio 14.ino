using System;

class Program
{
    static void Main()
    {
        int[,] matriz = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        Console.WriteLine("Matriz original:");
        ImprimirMatriz(matriz);

        RotarMatrizAIzquierda(matriz);

        Console.WriteLine("\nMatriz rotada a la izquierda:");
        ImprimirMatriz(matriz);
    }

    static void RotarMatrizAIzquierda(int[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        // Validar que la matriz no esté vacía
        if (filas == 0 || columnas == 0) return;

        // Guardar el primer elemento (fila 0, columna 0)
        int primerElemento = matriz[0, 0];

        // Desplazar cada elemento una posición a la izquierda
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if (j < columnas - 1)
                {
                    // Toma el elemento de su derecha en la misma fila
                    matriz[i, j] = matriz[i, j + 1];
                }
                else if (i < filas - 1)
                {
                    // Si es el último de la fila, toma el primero de la fila siguiente
                    matriz[i, j] = matriz[i + 1, 0];
                }
            }
        }

        // Colocar el primer elemento guardado en la última posición de la última fila
        matriz[filas - 1, columnas - 1] = primerElemento;
    }

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
