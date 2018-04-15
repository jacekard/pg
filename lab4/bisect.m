function [xvect,xdif,fx,it_cnt]=bisect(a,b,eps,fun)

    err = eps + 1;
    it_cnt = 0;
    xvect = [];
    fx = [];
    xdif = [];
    while (it_cnt < 10000 && err > eps)
        it_cnt = it_cnt + 1;
        c = (a+b)/2; 
        x = c;
        fc = feval(fun,x);
        xvect = [xvect;x];
        fx = [fx;fc]; 
        x = a;
        if (fc*feval(fun,x) > 0),
           a=c;
        else
           b=c;
        end;
        err=abs(b-a);
        xdif=[xdif;err];
    end;
end