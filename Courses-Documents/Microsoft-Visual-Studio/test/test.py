import math

# Các giá trị đã cho
N = 800                     # số vòng dây
l = 0.25                    # chiều dài cuộn dây (m)
r = 0.02                    # bán kính vòng dây (m)
mu_0 = 4 * math.pi * 1e-7   # độ từ thẩm của không khí (H/m)

# Diện tích mặt cắt ngang S
S = math.pi * r**2

# Tính hệ số tự cảm L
L = mu_0 * (N**2) * S / l

L_mH = L * 1e3  # đổi sang mH
L_mH
print(L_mH)