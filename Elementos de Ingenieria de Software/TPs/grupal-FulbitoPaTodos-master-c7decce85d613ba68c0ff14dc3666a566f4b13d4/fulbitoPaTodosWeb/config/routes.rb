Rails.application.routes.draw do
  devise_for :users
    resources :matches do
      collection do
        get :search
        get :searchResult
      end
    end

    root to: 'matches#index'
    #root to: 'users#sign_in'
end
