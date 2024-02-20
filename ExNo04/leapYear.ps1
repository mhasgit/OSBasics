echo "Enter the year"
$y = Read-Host
$r = $y % 4
if ($r -eq 0){
    echo "$y is a leap year"
}
else{
    echo "$y is not a leap year" 
}
