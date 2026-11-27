using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo (3 filas x 4 columnas)
        int[,] matriz = {
            { 10, 25, 8, 14 },
            { 45, 12, 99, 30 },
            { 5,  18, 22, 60 }
        };

        int filaABuscar = 1; // Segunda fila (índice 1)

        try
        {
            int columnaMaximo = ObtenerColumnaMaximoEnFila(matriz, filaABuscar);
            Console.WriteLine($"El elemento máximo en la fila {filaABuscar} está en la columna: {columnaMaximo}");
            // Salida esperada: 2 (porque el valor 99 está en la columna 2)
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }

    static int ObtenerColumnaMaximoEnFila(int[,] matriz, int fila)
    {
        int totalFilas = matriz.GetLength(0);
        int totalColumnas = matriz.GetLength(1);

        // Validar que el índice de la fila exista y que la matriz tenga columnas
        if (fila < 0 || fila >= totalFilas)
        {
            throw new ArgumentOutOfRangeException(nameof(fila), "El índice de fila está fuera de los límites de la matriz.");
        }
        if (totalColumnas == 0)
        {
            throw new ArgumentException("La matriz no tiene columnas.");
        }

        int columnaMax = 0;
        int valorMax = matriz[fila, 0];

        // Recorrer las columnas de la fila especificada empezando desde la columna 1
        for (int col = 1; col < totalColumnas; col++)
        {
            if (matriz[fila, col] > valorMax)
            {
                valorMax = matriz[fila, col];
                columnaMax = col;
            }
        }

        return columnaMax;
    }
}
