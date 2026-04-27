class Plant:
    def __init__(self, name, height, age, growth):
        self.name = name
        self.height = height
        self.age_d = age
        self.growth = growth

    def show(self):
        return f"{self.name}: {round(self.height, 1)}cm, {self.age_d} days old"

    def grow(self):
        self.height += self.growth

    def age(self):
        self.age_d += 1


def main() -> None:
    print("=== Garden Plant Growth ===")
    p = Plant("Rose", 25.0, 30, 0.8)
    print(p.show())
    for x in range(1, 8):
        print(f"=== Day {x} ===")
        p.grow()
        p.age()
        print(p.show())
    print(f"Growth this week: {round(0.8 * x, 1)}cm")


if __name__ == "__main__":
    main()
