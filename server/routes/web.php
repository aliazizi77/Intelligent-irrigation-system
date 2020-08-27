<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});

Auth::routes();

Route::get('/home', 'HomeController@index')->name('home');

Route::get('/device/create', 'DeviceController@create');
Route::get('/devices','DeviceController@index');
Route::post('/devices','DeviceController@store')->name('device.store');
Route::get('/devices/{id}','DeviceController@show')->name('device.show');
Route::put('/devices/{id}','DeviceController@update')->name('device.update');
Route::put('/devices/delete/{id}','DeviceController@destroy')->name('device.destroy');

