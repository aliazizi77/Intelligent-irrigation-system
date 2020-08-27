<aside class="main-sidebar">
    <!-- sidebar: style can be found in sidebar.less -->
    <section class="sidebar">
        <!-- Sidebar user panel -->
        <div class="user-panel">
            <div class="pull-right image">
                <img src="../../dist/img/user2-160x160.jpg" class="img-circle" alt="User Image">
            </div>
            <div class="pull-right info">
                <p>{{Auth::user()->name}}</p>
                <a href="#"><i class="fa fa-circle text-success"></i> آنلاین</a>
            </div>
        </div>

        <!-- sidebar menu: : style can be found in sidebar.less -->
        <ul class="sidebar-menu" data-widget="tree">
            <li class="header">منو</li>

            <li><a href="/home/"><i class="fa fa-dashboard"></i> <span>داشبورد</span></a></li>
            <!-- <li><a href="/point/"><i class="fa fa-dashboard"></i> <span>پنل</span></a></li>-->

            @if(Auth::user()->user_type == '1')


                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-window-maximize"></i>
                        <span>نرم افزار ها</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/buy/"><i class="fa fa-credit-card-alt"></i>خرید</a></li>
                        <li><a href="/licenses/"><i class="fa fa-certificate"></i>لایسنس ها</a></li>
                        <li><a href="/employees/create/"><i class="fa fa-desktop"></i>رایانه</a></li>
                    </ul>
                </li>
                <li><a href="/payments/"><i class="fa fa-dashboard"></i> <span>صورتحساب ها</span></a></li>
                <li><a href="/dashboard/"><i class="fa fa-dashboard"></i> <span>پشتیبانی</span></a></li>

                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-user"></i>
                        <span>حساب کاربری</span>
                        <span class="pull-left-container">
                      <i class="fa fa-angle-right pull-left"></i>
                    </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/profile/"><i class="fa fa-address-card"></i>پروفایل</a></li>
                        <li><a href="/employees/create/"><i class="fa fa-lock"></i>تغییر کلمه عبور</a></li>
                    </ul>
                </li>
            @endif
            @if(Auth::user()->user_type == '0')
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-code"></i>
                        <span>دستگاه ها</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/devices/"><i class="fa fa-code"></i>دستگاه ها</a></li>
                        <li><a href="/devices/create/"><i class="fa fa-code"></i>دستگاه جدید</a></li>
                    </ul>
                </li>
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-certificate"></i>
                        <span>لایسنس</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/users/"><i class="fa fa-certificate"></i>لایسنس ها</a></li>
                        <li><a href="/users/create/"><i class="fa fa-certificate"></i>ثبت لایسنس</a></li>

                    </ul>
                </li>
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-desktop"></i>
                        <span>رایانه</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/users/"><i class="fa fa-laptop"></i>رایانه های ثبت شده</a></li>
                        <li><a href="/users/create/"><i class="fa fa-laptop"></i>ثبت رایانه</a></li>

                    </ul>
                </li>
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-user"></i>
                        <span>کاربران</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/users/"><i class="fa fa-user"></i>همه کاربران</a></li>
                        <li><a href="/users/create/"><i class="fa fa-user"></i>افزودن کاربر</a></li>

                    </ul>
                </li>
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-user"></i>
                        <span>مشتریان</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/users/"><i class="fa fa-user"></i>همه مشتریان</a></li>
                        <li><a href="/users/create/"><i class="fa fa-user"></i>افزودن مشتری</a></li>

                    </ul>
                </li>
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-credit-card-alt"></i>
                        <span>صورتحساب ها</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/users/"><i class="fa fa-credit-card-alt"></i>همه صورتحساب ها</a></li>
                        <li><a href="/users/create/"><i class="fa fa-credit-card"></i>صورت حساب های پرداخت نشده</a></li>

                    </ul>
                </li>
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-comment"></i>
                        <span>تیکت</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/reports/"><i class="fa fa-commenting"></i>تیکت های باز</a></li>
                        <li><a href="/reports/archive/"><i class="fa fa-comments"></i>همه تیکت ها</a></li>

                    </ul>
                </li>
                <li class="treeview">
                    <a href="#">
                        <i class="fa fa-bar-chart"></i>
                        <span>گزارش</span>
                        <span class="pull-left-container">
              <i class="fa fa-angle-right pull-left"></i>
            </span>
                    </a>
                    <ul class="treeview-menu">
                        <li><a href="/reports/"><i class="fa fa-circle-o"></i>گزارش ماهانه</a></li>
                        <li><a href="/reports/archive/"><i class="fa fa-circle-o"></i>بایگانی</a></li>

                    </ul>
                </li>

            @endif


        </ul>
    </section>
    <!-- /.sidebar -->
</aside>
