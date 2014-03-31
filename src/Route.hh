<?hh
/**
 * Hack MVC
 *
 * This is a route.  It's a URL pattern that maps to a controller and an action.
 *
 *
 * @author Patrick Mizer
 */
class Route
{
    private string $controller;
    private string $action;
    
    public function __construct(string $controller, string $action) {
        $this->controller = $controller;
        $this->action = $action;
    }
    
    public function getController() : string {
        return $this->controller;
    }
    
    public function getAction() : string { 
        return $this->action;
    }
}