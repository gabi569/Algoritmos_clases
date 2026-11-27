using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo
        int[,] matriz = {
            { 12, 45, 7 },
            { 89, 23, 56 },
            { 34, 99, 10 }
        };

        // Llamamos al método y desestructuramos la tupla resultante
        var (fila, columna) = ObtenerPosicionMaximo(matriz);

        Console.WriteLine($"El elemento máximo es {matriz[fila, columna]}");
        Console.WriteLine($"Se encuentra en la posición: Fila {fila}, Columna {columna}");
    }

    /// <summary>
    /// Encuentra la posición (fila, columna) del valor máximo en una matriz de enteros.
    /// </summary>
    static (int fila, int columna) ObtenerPosicionMaximo(int[,] matriz)
    {
        // Validación básica por si la matriz viene vacía
        if (matriz == null || matriz.Length == 0)
        {
            throw new ArgumentException("La matriz no puede estar vacía.");
        }

        int maxValor = matriz[0, 0];
        int maxFila = 0;
        int maxColumna = 0;

        // GetLength(0) obtiene la cantidad de filas
        // GetLength(1) obtiene la cantidad de columnas
        for (int i = 0; i < matriz.GetLength(0); i++)
        {
            for (int j = 0; j < matriz.GetLength(1); j++)
            {
                if (matriz[i, j] > maxValor)
                {
                    maxValor = matriz[i, j];
                    maxFila = i;
                    maxColumna = j;
                }
            }
        }

        return (maxFila, maxColumna);
    }
}
