@extends('layouts.dashboard')
@section('content')
    <section class="content">

        <div class="row">
            <div class="col-md-12">
                <div class="box box-primary">
                    <div class="box-header with-border">
                        <h3 class="box-title">ویرایش دستگاه</h3>
                    </div>

                    <!-- /.box-header -->
                    <!-- form start -->
                    <div class="row">
                        <div class="col-md-6">
                            <form role="form" method="post" action="{{route('device.update',['id' =>$device->id ])}}">
                                {{csrf_field()}}
                                <input name="_method" type="hidden" value="PUT">
                                <div class="box-body">

                                    <div class="form-group">
                                        <label>نام</label>
                                        <input type="text" name="name" id="name" class="form-control" value="{{$device->name}}" placeholder="نام">
                                    </div>
                                    <div class="form-group">
                                        <label>شناسه دستگاه</label>
                                        <input type="number" name="device_id" id="device_id" class="form-control" value="{{$device->device_id}}" placeholder="شناسه دستگاه">
                                    </div>

                                    <div class="form-group">
                                        <label>توضیحات</label>
                                        <textarea rows="3" name="description" id="description" class="form-control"  placeholder="توضیحات">{{$device->description}}</textarea>
                                    </div>


                                </div>
                                <!-- /.box-body -->
                                @include('shared.errors')
                                <div class="box-footer">
                                    <button type="submit" class="btn btn-primary">ثبت</button>
                                </div>
                            </form>

                        </div>
                    </div>
                </div>                </div>
            <!-- /.col (right) -->
        </div>
        <!-- /.row -->

    </section>
@endsection