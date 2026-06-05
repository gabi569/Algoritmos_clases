using System;

class Program
{
    static void Invertir(string[] arreglo)
    {
        int inicio = 0;
        int fin = arreglo.Length - 1;

        while (inicio < fin)
        {
            string aux = arreglo[inicio];

            arreglo[inicio] = arreglo[fin];

            arreglo[fin] = aux;

            inicio++;
            fin--;
        }
    }

    static void Main()
    {
        string[] nombres = { "Ana", "Luis", "Pedro", "Maria" };

        Invertir(nombres);

        foreach (string nombre in nombres)
        {
            Console.Write(nombre + " ");
        }
    }
}