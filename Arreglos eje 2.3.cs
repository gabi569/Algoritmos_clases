using System;

class Program
{
    static void Main()
    {
        char[] Letras = { 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'a', 'b' };
        {
            bool[] Visitado = new bool[Letras.Length];

            for (int i = 0; i < Letras.Length; i++)
            {
                if (Visitado[i])
                    continue;

                int contador = 1;

                for (int j = i + 1; j < Letras.Length; j++)
                {
                    if (Letras[i] == Letras[j])
                    {
                        contador++;
                        Visitado[j] = true;
                    }
                }

                Console.WriteLine(Letras[i] + " aparece " + contador + " veces ");
            }
        }
    }
}