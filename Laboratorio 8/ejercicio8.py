def subarray_create(arr, k, threshold):
    valid_subarrays = []  

    
    for i in range(len(arr) - k + 1):
        subarray = arr[i:i+k]  
        avg = sum(subarray) / k  
        if avg >= threshold:
            valid_subarrays.append((subarray, avg)) 

    return valid_subarrays


arr = [12, 47, 3, 89, 25]
k = 4
i = 0
threshold = 6
valid = subarray_create(arr, k, threshold)


print("Subarreglos validos:")
for subarray, avg in valid:
    print(f"{subarray},{avg:.2f}")
    i = i + 1
print(i)
