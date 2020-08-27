<?php

namespace App\Http\Controllers;

use App\Device;
use Illuminate\Http\Request;
use Symfony\Component\HttpFoundation\Response;

class DeviceController extends Controller
{
    public function index()
    {
        $devices = Device::all();
        return view('device.index',compact('devices'));
    }

    public function create()
    {
        return view('device.create');
    }

    public function store(Request $request)
    {
        $this->validate($request,[
           'name' => 'required|max:255',
           'device_id' => 'required|numeric|max:99'
        ]);
        //dd($request);
        $device = Device::create($request->except('_token'));
        redirect('/devices/');
    }
    public function show($id)
    {
        $device = Device::find($id);
        return view('device.show',compact('device'));
    }
    public function update($id , Request $request)
    {
        Device::where('id','=',$id)->update($request->except('_token','_method'));
        return back();
    }
    public function destroy($id)
    {
        Device::destroy($id);
        return redirect('/devices');
        Response::
    }
}
