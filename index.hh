<?hh

require __DIR__.'/src/Controller.hh';
require __DIR__.'/src/Route.hh';
require __DIR__.'/src/Router.hh';


$router = new Router();
$router->registerRoute("/crazy-route", new Route("Foo", "index"));

$router->dispatch();