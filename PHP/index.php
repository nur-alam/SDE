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

function shouldRemovePrimaryKey($value)
{
	return $value === null || $value === '' || $value === 0;
}
// echo empty(shouldRemovePrimaryKey([])) . PHP_EOL;
