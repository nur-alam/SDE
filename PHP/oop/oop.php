<?php
abstract class Vehicle {
	abstract public function drive(): void;

	public function honk(): void {
		echo "Honk!\n";
	}
}

class Car extends Vehicle {
	public function drive(): void {
		echo "Driving a car on four wheels.\n";
	}
}

class Motorcycle extends Vehicle {
	public function drive(): void {
		echo "Riding a motorcycle on two wheels.\n";
	}
}

// $myCar = new Car();
// $myCar->drive(); // Output: Driving a car on four wheels.
// $myCar->honk(); // Output: Honk!
class Model {
	public $attributes = array();
	protected $juicy      = '';
	public function __construct() {
		echo "Model initialized.\n";
	}
	public function __set( $name, $value ) {
		$this->attributes[ $name ] = $value;
	}
}

$model             = new Model();
$model->attributes = 'atgtpops';
print_r( $model );
var_dump( $model );
