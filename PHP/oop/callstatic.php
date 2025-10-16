<?php

#[\Attribute]
class IsBackground {
	public function __construct(
		public readonly ?int $delay = null
	) { }
}

#[IsBackground]
class Operation {
	// properties and methods
}

$reflectionClass = new \ReflectionClass( new Operation() );
$attributes      = $reflectionClass->getAttributes( IsBackground::class );
$attr            = reset( $attributes );
$attrObject      = $attr->newInstance();

echo $attrObject->delay;
