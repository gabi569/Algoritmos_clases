using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo 3x3
        int[,] matriz = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        Console.WriteLine("Matriz original:");
        ImprimirMatriz(matriz);

        RotarDerecha(matriz);

        Console.WriteLine("\nMatriz rotada a la derecha:");
        ImprimirMatriz(matriz);
    }

    static void RotarDerecha(int[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        // Si la matriz está vacía o tiene un solo elemento, no hace falta rotar
        if (filas == 0 || columnas == 0 || (filas == 1 && columnas == 1))
            return;

        // Guardamos el último elemento (esquina inferior derecha)
        int ultimoElemento = matriz[filas - 1, columnas - 1];

        // Recorremos la matriz desde el final hacia el principio
        for (int i = filas - 1; i >= 0; i--)
        {
            for (int j = columnas - 1; j >= 0; j--)
            {
                // Si llegamos a la primera posición, salimos del bucle
                if (i == 0 && j == 0)
                    break;

                if (j > 0)
                {
                    // Toma el valor de la posición anterior en la misma fila
                    matriz[i, j] = matriz[i, j - 1];
                }
                else
                {
                    // Si está en la primera columna (j == 0), toma el último valor de la fila anterior
                    matriz[i, j] = matriz[i - 1, columnas - 1];
                }
            }
        }

        // Colocamos el último elemento guardado en la primera posición [0,0]
        matriz[0, 0] = ultimoElemento;
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
