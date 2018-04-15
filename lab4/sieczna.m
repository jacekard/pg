function [xvect,xdif,fx,it_cnt] = sieczna(x1,x0,eps,fun)

    x = x1;
    fx1 = feval(fun,x);
    xvect = [x];
    fx = [fx1]; 
    x = x0;
    fx0 = feval(fun,x);
    xvect = [xvect;x];
    fx = [fx;fx0];
    err = eps+1;
    it_cnt = 0;
    xdif = [];
    while (err > eps),
        it_cnt = it_cnt + 1;
        x = x0-fx0*(x0-x1)/(fx0-fx1);
        xvect = [xvect;x];
        fnew = feval(fun,x);
        fx = [fx; fnew];
        err = abs(x0-x);
        xdif = [xdif;err];
        x1 = x0;
        fx1 = fx0;
        x0 = x;
        fx0 = fnew;
    end;