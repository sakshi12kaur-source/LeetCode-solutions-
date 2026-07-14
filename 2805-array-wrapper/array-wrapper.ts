class ArrayWrapper {
  private nums: number[];

  constructor(nums: number[]) {
    this.nums = nums;
  }

  valueOf(): number {
    return this.nums.reduce((acc, curr) => acc + curr, 0);
  }

  toString(): string {
    return JSON.stringify(this.nums);
  }
}

const obj1 = new ArrayWrapper([1, 2]);
const obj2 = new ArrayWrapper([3, 4]);

// console.log(obj1 + obj2); // 10
// console.log(String(obj1)); // "[1,2]"
// console.log(String(obj2)); // "[3,4]"