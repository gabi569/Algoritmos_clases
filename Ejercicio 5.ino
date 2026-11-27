using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo
        int[,] matriz = {
            { 12, 45, 3 },
            { 8, 99, 24 },
            { 50, 14, 71 }
        };

        int[] filaConMaximo = ObtenerFilaDelMaximo(matriz);

        Console.WriteLine("La fila que contiene el elemento máximo es:");
        Console.WriteLine(string.Join(", ", filaConMaximo));
    }

    static int[] ObtenerFilaDelMaximo(int[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        int maxElemento = matriz[0, 0];
        int filaMaximo = 0;

        // 1. Buscar la posición (fila) del elemento máximo
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if (matriz[i, j] > maxElemento)
                {
                    maxElemento = matriz[i, j];
                    filaMaximo = i;
                }
            }
        }

        // 2. Extraer y devolver la fila completa
        int[] filaResultado = new int[columnas];
        for (int j = 0; j < columnas; j++)
        {
            filaResultado[j] = matriz[filaMaximo, j];
        }

        return filaResultado;
    }
}
