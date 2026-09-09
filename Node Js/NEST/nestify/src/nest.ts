function AddTimestamp<T extends new (...args: any[]) => {}>(target: T) {
  return class extends target {
    createdAt = new Date();
  };
}

// function AddTimestamp(target: new (...args: any[]) => {}) {
//   console.log('target', target);
//   return class extends target {
//     createdAT = new Date();
//   };
// }

@AddTimestamp
class User {
  juicy = 'pops';
  constructor(name: string) {
    console.log('args name', name);
  }
}

// const user = new User('juicy');
// console.log('user', user);
// console.log(new class { name = 'juicy' }().name);

// // Method decorators
// function Log(target: any, propertyKey: string, descriptor: PropertyDescriptor) {
//   console.log(target);
//   console.log(propertyKey);
//   console.log('descriptor',descriptor);
// }

// class UserService {
//   @Log
//   getUsers() {
//     return [];
//   }
// }

// Decorator factory: @Log('nur') passes a value into the wrapper
function Log(extra: string) {
  return function (target: any, propertyKey: string, descriptor: PropertyDescriptor) {
    const originalMethod = descriptor.value;
    descriptor.value = function (...args: any[]) {
      console.log('Before method', args);
      const result = originalMethod.apply(this, args);
      const withExtra = [...result, extra];
      console.log('After method', withExtra);
      return withExtra;
    };
  };
}

class UserService {
  @Log('nur')
  getUsers(extraName: string) {
    console.log('Getting users arguments', arguments);
    console.log('this', this);
    return ['John', 'Jane', extraName];
  }
}

const service = new UserService();
const k = service.getUsers('jassy');
console.log('k',k);
