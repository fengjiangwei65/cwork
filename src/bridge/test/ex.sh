#!/bin/bash

#./admin_create_pin   E1:93:2A:A3:16:E7 8d29d572299deda54de78c16fcce1451  35f1cfb6f8bee257  $1

#sudo ./admin_create_pin   FB:98:0C:E9:57:5D  182CFF90BCD2D53A856A4B9C15ECA771  3A562F52A40D79C4  $1

#./admin_unlock EC:09:02:7F:4B:09  BD3967AE24FD72B750C4E48B89294592   7E2113D9235EA288  $1
./admin_get_lock_status EC:09:02:7F:4B:09  BD3967AE24FD72B750C4E48B89294592   7E2113D9235EA288  $1

sudo ./guest_unlock  EC:09:02:7F:4B:09  65e2fb6511fac1dc3a9722e9a2c56606   63c5bd7dd34fe863  31931847906e1c650ebb3a27fda90b26fb583673f44553627da9f24ca3197d871a18f482608a4f7ec66337ff828b5a2b45edd072d7c2e12cc9d68bcff353e3980ad8b70b92b9


