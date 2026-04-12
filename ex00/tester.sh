# toChar test
echo "Conversion from Character"
./convert a
echo ''
./convert 'b'
echo ''
./convert '*'
echo ''
./convert ' '
echo ''
./convert '}'
echo ''

# toInt test
echo "Conversion from Integer"
./convert 0
echo ''
./convert 42
echo ''
./convert 32
echo ''
./convert 125
echo ''
./convert 2147483647
echo ''
./convert -2147483648
echo ''
./convert 2147483647901
echo ''
./convert -2147483647901
echo ''

# toFloat test
echo "Conversion from Float"
./convert 0.0f
echo ''
./convert 4.2f
echo ''
./convert 42.0f
echo ''
./convert -42.0f
echo ''
./convert 2147483647.0f
echo ''
./convert -2147483648.0f
echo ''
./convert 2147483647901.0f
echo ''
./convert -2147483647901.0f
echo ''
./convert 34028453434444434342342342909f
echo ''
./convert 3402845343444443434234234290900000000000000000000f
echo ''
./convert -3402845343444443434234234290900000000000000000000f
echo ''

# toDouble test
echo "Conversion from Double"
./convert 0.1
echo ''
./convert 4.2
echo ''
./convert 42.7
echo ''
./convert -42.0
echo ''
./convert 2147483647.0
echo ''
./convert -2147483648.0
echo ''
./convert 2147483647901.0
echo ''
./convert -2147483647901.0
echo ''
./convert 34028453434444434342342342909.1
echo ''
./convert 3402845343444443434234234290900000000000000000000.1
echo ''
./convert -3402845343444443434234234290900000000000000000000.9
