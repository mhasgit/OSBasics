echo "Enter the Number"
$n = Read-Host
$r = $n % 2
if ($r -eq 0) {
    echo "$n is an Even number"
} else {
    echo "$n is an Odd number"
}
