function fn = myfs(Dn, omega0, t)    
    N = (length(Dn) - 1) / 2;
    
    fn = (Dn(2 * N + 1)) * (ones(1, length(t)));
    
    w = omega0;
    
    for k = -N:-1
        ck = Dn(-k);
        fn = fn + real(ck * exp(1j * k * w * t));
    end

    for k = 1:N
        ck = Dn(k + N);
        fn = fn + real(ck * exp(1j * k * w * t));
    end
end





