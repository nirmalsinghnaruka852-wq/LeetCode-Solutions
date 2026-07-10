/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
   let length = nums.length ;
   let map = new Map()
   for(let i =0 ; i< length ; i ++){
    let value = target - nums[i]
    if(map.has(value)){
        return [i, map.get(value)]
    }
    map.set(nums[i] ,i)
   }
   return []
 
};