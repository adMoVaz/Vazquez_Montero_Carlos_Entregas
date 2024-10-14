import random
import math
import time

def euclidean_distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def closest_pair(points):
    def closest_pair_recursive(points_sorted_x, points_sorted_y):
        if len(points_sorted_x) <= 3:
            return brute_force_closest_pair(points_sorted_x)

        mid = len(points_sorted_x) // 2
        midpoint = points_sorted_x[mid]

        left_x = points_sorted_x[:mid]
        right_x = points_sorted_x[mid:]
        
        left_y = list(filter(lambda x: x[0] <= midpoint[0], points_sorted_y))
        right_y = list(filter(lambda x: x[0] > midpoint[0], points_sorted_y))

        (p1, q1, min_dist1) = closest_pair_recursive(left_x, left_y)
        (p2, q2, min_dist2) = closest_pair_recursive(right_x, right_y)

        min_dist = min(min_dist1, min_dist2)
        if min_dist == min_dist1:
            closest_pair = (p1, q1)
        else:
            closest_pair = (p2, q2)

        strip = [p for p in points_sorted_y if abs(p[0] - midpoint[0]) < min_dist]
        for i in range(len(strip)):
            for j in range(i + 1, min(i + 7, len(strip))):
                p, q = strip[i], strip[j]
                dist = euclidean_distance(p, q)
                if dist < min_dist:
                    min_dist = dist
                    closest_pair = (p, q)

        return closest_pair[0], closest_pair[1], min_dist

    def brute_force_closest_pair(points):
        min_dist = float('inf')
        closest_pair = (None, None)
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                dist = euclidean_distance(points[i], points[j])
                if dist < min_dist:
                    min_dist = dist
                    closest_pair = (points[i], points[j])
        return closest_pair[0], closest_pair[1], min_dist

    points_sorted_x = sorted(points, key=lambda x: x[0])
    points_sorted_y = sorted(points, key=lambda x: x[1])

    return closest_pair_recursive(points_sorted_x, points_sorted_y)

num_points = int(input("Ingrese la cantidad de numeros a generar: "))
points = [(round(random.uniform(-9999, 9999), 1), round(random.uniform(-9999, 9999), 1)) for _ in range(num_points)]
print("Pares de puntos generados:", points)

start_time = time.perf_counter()
point1, point2, min_distance = closest_pair(points)
end_time = time.perf_counter()

elapsed_time_microseconds = (end_time - start_time) * 1_000_000 

print(f"El par de puntos más cercanos son el punto {point1} y el punto {point2} con una distancia de: {round(min_distance, 1)}")
print(f"Tiempo de ejecución: {elapsed_time_microseconds:.0f} microsegundos")
