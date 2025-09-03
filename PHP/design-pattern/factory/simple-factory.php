<?php
/**
 * Simple factory design pattern
 *
 * @package simple factory
 */

interface PaymentGateway {
	/**
	 * Pay method
	 *
	 * @param float $amount Amount to pay.
	 */
	public function pay( float $amount );
}

class Paypal implements PaymentGateway {
	public function pay( float $amount ) {
		echo "Paying $amount using Paypal 💰 \n";
	}
}

class Stripe implements PaymentGateway {
	public function pay( float $amount ) {
		echo "Paying $amount using Stripe 💰 \n";
	}
}

class PaymentFactory {
	public static function create( string $gateway ): PaymentGateway {
		return match ( strtolower( $gateway ) ) {
			'paypal' => new Paypal(),
			'stripe' => new Stripe(),
			'default' => throw new Exception( "Unknown payment gateway: $gateway" )
		};
	}
}

$payment = PaymentFactory::create( 'paypal' );
$payment->pay( 40 );
$stripe_payment = PaymentFactory::create( 'stripe' );
$stripe_payment->pay( 30 );
