using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo
        int[,] matriz = {
            { -5, 10, 0 },
            { 3, -2, 8 },
            { 7, -1, 4 }
        };

        int cantidadPositivos = ContarPositivos(matriz);
        Console.WriteLine($"La matriz contiene {cantidadPositivos} elementos positivos.");
    }

    static int ContarPositivos(int[,] matriz)
    {
        int contador = 0;

        // Recorre las filas (dimensión 0)
        for (int i = 0; i < matriz.GetLength(0); i++)
        {
            // Recorre las columnas (dimensión 1)
            for (int j = 0; j < matriz.GetLength(1); j++)
            {
                if (matriz[i, j] > 0)
                {
                    contador++;
                }
            }
        }

        return contador;
    }
}
