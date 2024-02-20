echo "Enter Two Numbers"
$input = Read-Host -Prompt "Enter numbers separated by a space"
$a, $b = $input -split ' '

$temp = $a
$a = $b
$b = $temp

echo "After swapping:"
echo "First Number: $a"
echo "Second Number: $b"
