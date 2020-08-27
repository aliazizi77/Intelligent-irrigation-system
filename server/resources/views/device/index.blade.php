@extends('layouts.dashboard')
@section('content')
    <section class="content">
        <div class="row">
            <div class="col-xs-12">
                <div class="box">
                    <div class="box-header">
                        <h3 class="box-title">لیست دستگاه ها</h3>

                        <div class="box-tools">
                            <div class="input-group input-group-sm" style="width: 150px;">
                                <input type="text" name="table_search" class="form-control pull-right" placeholder="جستجو">

                                <div class="input-group-btn">
                                    <button type="submit" class="btn btn-default"><i class="fa fa-search"></i></button>
                                </div>
                            </div>
                        </div>
                    </div>
                    <!-- /.box-header -->
                    <div class="box-body table-responsive no-padding">
                        <table class="table table-hover">
                            <tr>
                                <th>نام</th>
                                <th>شناسه</th>
                                <th>عملیات</th>
                            </tr>
                            @foreach($devices as $device)
                                <tr>
                                    <td>{{$device->name}}</td>
                                    <td>{{$device->id}}</td>
                                    <td>
                                        <button class="btn btn-success" type="button" onclick="window.location.href='/devices/{{$device->id}}'">ویرایش</button>
                                        <button class="btn btn-danger" type="button" onclick="window.location.href='/devices/{{$device->id}}'">حذف</button>
                                    </td>
                                </tr>

                            @endforeach
                        </table>
                    </div>
                    <!-- /.box-body -->
                </div>
                <!-- /.box -->
            </div>
        </div>
    </section>

@endsection