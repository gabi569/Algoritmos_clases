using System;

class ProgramaMatrizInversa
{
    static void Main()
    {
        double[,] matriz = {
            { 4, 7 },
            { 2, 6 }
        };

        try
        {
            double[,] inversa = CalcularInversa(matriz);
            Console.WriteLine("Matriz Inversa:");
            ImprimirMatriz(inversa);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }

    public static double[,] CalcularInversa(double[,] matriz)
    {
        int n = matriz.GetLength(0);

        if (n != matriz.GetLength(1))
            throw new ArgumentException("La matriz debe ser cuadrada.");

        // Crear matriz aumentada [A | I]
        double[,] aumentada = new double[n, 2 * n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                aumentada[i, j] = matriz[i, j];
            }
            aumentada[i, i + n] = 1.0;
        }

        // Aplicar eliminación de Gauss-Jordan
        for (int i = 0; i < n; i++)
        {
            // Buscar el pivote máximo en la columna actual para evitar división por cero
            int maxFila = i;
            for (int k = i + 1; k < n; k++)
            {
                if (Math.Abs(aumentada[k, i]) > Math.Abs(aumentada[maxFila, i]))
                    maxFila = k;
            }

            // Intercambiar filas
            for (int k = 0; k < 2 * n; k++)
            {
                double temp = aumentada[i, k];
                aumentada[i, k] = aumentada[maxFila, k];
                aumentada[maxFila, k] = temp;
            }

            double pivote = aumentada[i, i];
            if (Math.Abs(pivote) < 1e-10)
                throw new InvalidOperationException("La matriz es singular y no tiene inversa.");

            // Normalizar la fila del pivote
            for (int j = 0; j < 2 * n; j++)
            {
                aumentada[i, j] /= pivote;
            }

            // Hacer ceros en el resto de la columna
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    double factor = aumentada[k, i];
                    for (int j = 0; j < 2 * n; j++)
                    {
                        aumentada[k, j] -= factor * aumentada[i, j];
                    }
                }
            }
        }

        // Extraer la matriz inversa de la parte derecha
        double[,] inversa = new double[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                inversa[i, j] = aumentada[i, j + n];
            }
        }

        return inversa;
    }

    private static void ImprimirMatriz(double[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                Console.Write($"{matriz[i, j]:F2}\t");
            }
            Console.WriteLine();
        }
    }
}
