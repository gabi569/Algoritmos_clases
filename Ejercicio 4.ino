using System;

class Program
{
    static void Main()
    {
        // Ejemplo de matriz de enteros (4 filas x 3 columnas)
        int[,] matriz = {
            { 12, 45, 7 },
            { 89, 23, 54 },
            { 34, 91, 18 },
            { 67, 10, 82 }
        };

        int columnaBuscada = 1; // Segunda columna (índice 1)

        try
        {
            int filaMaximo = ObtenerFilaConMaximoEnColumna(matriz, columnaBuscada);
            Console.WriteLine($"En la columna {columnaBuscada}, el valor máximo se encuentra en la fila: {filaMaximo}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }

    static int ObtenerFilaConMaximoEnColumna(int[,] matriz, int columna)
    {
        // Validaciones básicas
        if (matriz == null || matriz.GetLength(0) == 0 || matriz.GetLength(1) == 0)
        {
            throw new ArgumentException("La matriz no puede ser nula ni estar vacía.");
        }

        if (columna < 0 || columna >= matriz.GetLength(1))
        {
            throw new ArgumentOutOfRangeException(nameof(columna), "El índice de columna está fuera de los límites de la matriz.");
        }

        int filaConMaximo = 0;
        int valorMaximo = matriz[0, columna];

        // Recorremos todas las filas (dimensión 0) manteniendo fija la columna
        for (int fila = 1; fila < matriz.GetLength(0); fila++)
        {
            if (matriz[fila, columna] > valorMaximo)
            {
                valorMaximo = matriz[fila, columna];
                filaConMaximo = fila;
            }
        }

        return filaConMaximo;
    }
}
