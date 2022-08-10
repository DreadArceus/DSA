const auto sqrt = [](ld x) -> ld {
    ld l = 0, r = x;
    for (int i = 0; i < 100; i++)
    {
        ld mid = midpoint(l, r);
        if (mid * mid < x)
            l = mid;
        else
            r = mid;
    }
    return l;
};
