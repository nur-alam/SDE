<?php
/**
 * General php code here.
 *
 * @package index
 */
abstract class Base {
	public static function yo() {
		$instance = new static();
		echo 'yo ' . PHP_EOL;
	}
}

class Model extends Base {
	public function __construct() {
		echo 'model constructor ' . PHP_EOL;
	}
}

// Model::yo();
$mysql_functions = [
	'NOW()',
	'CURDATE()',
	'CURTIME()',
	'CURRENT_DATE()',
	'CURRENT_TIME()',
	'CURRENT_TIMESTAMP()',
	'UTC_DATE()',
	'UTC_TIME()',
	'UTC_TIMESTAMP()'
];

// $j = 'NOW()';
// $d = in_array($j, $mysql_functions);

function shouldRemovePrimaryKey($value) {
	return $value === null || $value === '' || $value === 0;
}
// echo empty(shouldRemovePrimaryKey([])) . PHP_EOL;
class A {
    public $one = '';
    public $two = '';

    public function echoOne() { echo $this->one . "\n"; }
    public function echoTwo() { echo $this->two . "\n"; }
}
$a = new A();
$reflector = new ReflectionClass('A');
$properties = $reflector->getProperties();
// print_r($properties);
$i = 1;
foreach ($properties as $property) {
    // Dynamically set property values
    $a->{$property->getName()} = 'juicy ' . $i;
    // Dynamically call methods
    $a->{"echo" . ucfirst($property->getName())}();
    $i++;
}
echo 'reflection!' . PHP_EOL;
