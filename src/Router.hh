<?hh
class Router
{
    private Map<string, Route> $routeMap;
    
    public function registerRoute(string $pattern, Route $route) : void {
        $this->routeMap[$pattern] =  $route;
    }
}