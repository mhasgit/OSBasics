echo "Enter a Number"
$n = Read-Host
$factorial = 1

for ($i = 2; $i -le $n; $i++) {
    $factorial = $factorial * $i
}

echo "The Factorial of the given number is $factorial"
