using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo (3 filas x 4 columnas)
        int[,] matriz = {
            { 12,  45,   8, 19 },
            { 33,  10,  99,  4 },
            { 21,  67,  15, 88 }
        };

        int columnaMaximo = ObtenerColumnaDelMaximo(matriz);
        
        Console.WriteLine($"La columna que contiene el elemento máximo es la: {columnaMaximo}");
    }

    static int ObtenerColumnaDelMaximo(int[,] matriz)
    {
        // Validación básica para evitar errores si la matriz está vacía
        if (matriz == null || matriz.Length == 0)
        {
            throw new ArgumentException("La matriz no puede ser nula ni estar vacía.");
        }

        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        // Inicializamos con el primer elemento de la matriz
        int maximo = matriz[0, 0];
        int columnaDelMaximo = 0;

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if (matriz[i, j] > maximo)
                {
                    maximo = matriz[i, j];
                    columnaDelMaximo = j;
                }
            }
        }

        return columnaDelMaximo;
    }
}
