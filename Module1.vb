Imports System.Math
Module Module1

    Sub Main()
        Dim Npts As Integer = 1000
        Dim y, xmin, xmax, interval, delta_x As Single
        Dim sum As Single
        Const PI As Single = 3.14159265
        Console.WriteLine("develop Area under the curve of a function")

        'establish number of points Npts here:
        sum = 0.0
        'establish endpoints (xmin, xmax) here:
        xmin = 0.0
        xmax = PI
        'xmax = 1.0
        interval = xmax - xmin
        delta_x = (xmax - xmin) / Npts

        Console.WriteLine("N,  Sin ")
        For N = 1 To Npts
            'establish function here:
            y = (Math.Sin(PI * N / Npts)) ^ 2    'SINE FUNCTION squared
            'x = xmin + N * delta_x
            ' y = Sqrt(1 - x * x)                   'circle (1/4)
            '            Console.WriteLine()
            '           Console.Write(N)
            '          Console.Write("  ")
            '         Console.Write(y)
            sum = sum + y * delta_x             ' the area is the sum
            'rms squared is area squared/interval
        Next N
        Console.WriteLine()
        Console.WriteLine("sum y_squared / interval= rms squared ")
        Console.Write(sum / interval)
        Console.WriteLine()
        Console.WriteLine("rms= ")
        Console.Write(Sqrt(sum / interval))
        Dim s As String = Console.ReadLine  'pause for input to read screen enter Npts later

    End Sub

End Module
